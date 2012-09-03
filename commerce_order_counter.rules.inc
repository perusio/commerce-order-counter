<?php

// TODO : Still need to attach that action when enabling the module to the Checkout completion Rule.
// rules config load : commerce_checkout_order_status_update
//

/**
 * Implementation of hook_rules_action_info().
 *
 * Create the action to update the order number with the order-counter token.
 */
function commerce_order_counter_rules_action_info() {
  $actions = array();

  $actions['commerce_order_counter_update_order_number'] = array(
    'label' => t('Update the order number'),
    'parameter' => array(
      'commerce_order' => array(
        'type' => 'commerce_order',
        'label' => t('Order to update'),
      ),
      'order_number' => array(
        'type' => 'text',
        'label' => t('Order number'),
        'description' => t('Select the order number that you want to use to update the completed order.<br/>It uses the [site:order-counter] by default. Keep that value unless you\'re sure of what you\'re doing...'),
        'default value' => '[site:order-counter]',
      ),
    ),
    'group' => t('Commerce (contrib)'),
    'callbacks' => array(
      'execute' => 'commerce_order_counter_rules_update_number',
    ),
  );

  return $actions;
}

/**
 * Rules action callback.
 */
function commerce_order_counter_rules_update_number($order, $number) {
  // Update the order number using the $number parameter. By default, it's set to the [site:order-counter] token.
  commerce_order_counter_number_update($order, $number, FALSE, NULL, t('Order number updated via Rules.'));
}
