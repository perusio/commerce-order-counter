<?php
/**
 * @file
 * Token callbacks for the commerce_order_counter module.
 */

/**
 * Implements hook_token_info().
 */
function commerce_order_counter_token_info() {
  $tokens['order-counter'] = array(
    'name' => t('Order counter'),
    'description' => t('Number of completed orders.'),
  );

  return array(
    'tokens' => array('user' => $tokens),
  );
}

/**
 * Implements hook_tokens().
 */
function ccommerce_order_counter_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();
  if ($type == 'user') {
    if (isset($tokens['order-counter'])) {
      $replacements[$tokens['order-counter']] = commerce_order_counter_get_order_counter();
    }
  }
  return $replacements;
}
